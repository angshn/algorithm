#!/root/miniconda3/bin/python3.10
import argparse
import os
import glob
from enum import Enum
import sys
import shutil
from yaml import load, dump,CLoader as Loader
PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
CPP_TEMPLATE = PROJECT_ROOT+os.path.sep+"/templates/template.txt"


class InfoType(Enum):
    ERROR   =   0
    SUCCESS =   1
    WARNING =   2
    INFO    =   3
    OTHER   =   4

def read(path):
    
    with open(os.path.dirname(__file__)+os.path.sep+path,'r') as f:
        text = f.read()
    return text

def printk(typ, *info):
    """Print info with given information type

    Args:
        typ (int): color 
        info (string): Want to print information
    """
    _heads = ['\033[1;31m','\033[0;1;32m','\033[1;33m','\033[1;34m','\033[1;35m','\033[0m']
    print(f'{_heads[typ.value]}',*info,f'{_heads[-1]}')

def clean():
    """Cleaning the directory
    """
    modes=[f"{PROJECT_ROOT}/**/*.out"]
    removeFileList = glob.glob(modes[0],recursive=True)
    # print(*removeFileList,sep="\n")
    if len(removeFileList) == 0:
        printk(InfoType.WARNING, "cleaned.")
        return
    
    for fi in removeFileList:
        printk(InfoType.WARNING, f"removing: {os.path.relpath(fi ,PROJECT_ROOT)}")
        # print(os.path.realpath(fi))
        os.remove(fi)
    
def getTemplate():

    with open(CPP_TEMPLATE,"r") as ff:
        templ = ff.read()
        # ! do replace
        options=conf["config"]["options"]
        keys = options.keys()
        for i in keys:
            templ = templ.replace(i,options[i])
    return templ

def copyTemplate(dest, templ):
    with open(dest,"w") as f:
        f.write(templ)


def startContest(contestId, size, path):
    """Starting a new codeforces contest using the given const number and the number of problems

    Args:
        contestId (int): id of the codeforces contest, it is a unique integer
        size (int): The number of problems of this contest
    """
    if not os.path.exists(path):
        os.makedirs(path)
    
    targetpath = path+os.path.sep+"doing"+os.path.sep+contestId
    if not os.path.exists(targetpath):
        os.makedirs(targetpath)
    files = os.listdir(targetpath)
    if len(files) != 0:
        printk(InfoType.WARNING,"Exsit some file")
    templ = getTemplate()
    for i in range(size):
        name = chr(ord('A')+i)+'.cpp'
        if name not in files:
            filename = targetpath +os.path.sep + name
            copyTemplate(filename, templ)
        else:
            printk(InfoType.WARNING, name ," is exist")

def makesure(path):
    if not os.path.exists(path):
        os.makedirs(path)


def startSingle(problemSeq):
    path = args.path+os.path.sep+args.platform+os.path.sep+"doing"
    makesure(path)
    targetpath = path+os.path.sep+problemSeq+".cpp"
    templ = getTemplate()
    copyTemplate(targetpath, templ)
    printk(InfoType.INFO, f"make file in {targetpath}.")

def accecp(problem, dir=None):
    """Moving the problem file to done directory.

    Args:
        problem (str): A file name you want to accept
    """
    target = os.path.join(PROJECT_ROOT, args.platform, "done")
    path = os.path.join(PROJECT_ROOT,args.platform,"doing")
    if dir is not None:
        path = os.path.join(path,dir)
        makesure(os.path.join(target,dir))
        target = os.path.join(target,dir)
    
    path = os.path.join(path,problem+".cpp")
    if os.path.exists(path):
        shutil.move(path, os.path.join(target,problem+".cpp"))
    



def getArgs():
    parser = argparse.ArgumentParser(description="Competitive Programming Tools",usage="It is a effective tool for doing competitive programming")
    parser.add_argument('--contest',type=str,dest="contestId",help="the contest id you wang to add. sucn as contest id 1800",metavar= ["1702"])
    parser.add_argument('--contest-size',type=int,dest="contestSize",help="the number of problems that given contest contains",metavar=["6","8"],default=6)
    parser.add_argument('--path',type=str,dest="path",help="Giving a target directory to save the contest/problems.", default=os.path.realpath(os.path.dirname(os.path.dirname(__file__))))
    parser.add_argument('--clean',dest="clean",action='store_true',help="Clean the project, default to remove the .out and other files and directories.")
    parser.add_argument('--allkill',type=str,help="Accept a contest id, generally, this operation will move the target contest directory to $PROJECT_ROOT/done, except that, it will clean the target dir.")
    parser.add_argument('--accept',type=str,dest="fid", help="Accept single problem, move it to done directory")
    parser.add_argument('--platform', type=str, dest="platform",help="The platform you want to play, such as codeforces, luogu etc", default="codeforces")
    parser.add_argument('--single',type=str,dest="singleProblem",help="create a single file")
    args = parser.parse_args()
    return args

if __name__ == "__main__":
    args = getArgs()
    conf = load(read("config.yaml"),Loader=Loader)

    if args.singleProblem:
        startSingle(args.singleProblem)

    if args.clean:
        clean()
        
    if args.contestId and args.contestSize:
        startContest(args.contestId,args.contestSize, args.path+os.path.sep+args.platform)

    if args.fid:
        accecp(args.fid)
    
    