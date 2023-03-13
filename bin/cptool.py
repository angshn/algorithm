#!/root/miniconda3/bin/python3.10
import argparse
import os
import glob
from enum import Enum
import sys
PROJECT_ROOT = "/root/devel/algorithm"



class InfoType(Enum):
    ERROR = 0
    SUCCESS = 1
    WARNING = 2
    INFO = 3
    OTHER = 4


def printk(typ, *info):
    """Print info with given color type

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
    
    


def NewContest(contestId, size):
    """Starting a new codeforces contest using the given const number and the number of problems

    Args:
        contestId (int): id of the codeforces contest, it is a unique integer
        size (int): The number of problems of this contest
    """
    

    
    

def getArgs():
    parser = argparse.ArgumentParser(description="Competitive Programming Tools",usage="It is a effective tool for doing competitive programming")
    parser.add_argument('--contest',type=str,dest="contest",help="the contest id you wang to add. sucn as contest id 1800",metavar= ["1702"])
    parser.add_argument('--size',type=int,dest="sizeProblems",help="the number of problems that given contest contains",metavar=["6","8"])
    parser.add_argument('--path',type=str,dest="path",help="Giving a target directory to save the contest/problems.", default=os.path.realpath('../'))
    parser.add_argument('--clean',dest="clean",action='store_true',help="Clean the project, default to remove the .out and other files and directories.")
    parser.add_argument('--accept',type=str,help="Accept a contest id, generally, this operation will move the target contest directory to $PROJECT_ROOT/done, except that, it will clean the target dir.")

    args = parser.parse_args()
    return args

if __name__ == "__main__":
    

    args = getArgs()
    
    if args.clean:
        clean()
    
    # printk(InfoType.ERROR,"hello"," world", "codeforces")
    pass

