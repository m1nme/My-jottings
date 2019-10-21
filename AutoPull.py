import os
import sys
import subprocess
try:
    from argparse import ArgumentParser as ArgParser
except ImportError:
    from optparse import OptionParser as ArgParser
def printcmd(cmd):
    subprocess.call(cmd, shell=True)
    print("")
def shell():
    gitcounter = 0
    for g in os.listdir():
        try:
            if os.path.isdir(g) and ".git" in os.listdir(g):
                print(g)
                printcmd("cd {} && git pull".format(g))
                gitcounter += 1
        except PermissionError:
            print('{}\nSkipping this folder because no permission/wrong folder\n'.format(g))
    print("Successfully git pulled on {} subfolder{}".format(
        gitcounter,
        "" if gitcounter == 1 else "s"
    ))
if __name__ == '__main__':
    try:
        shell()
    except KeyboardInterrupt:
        print('\nCancelling...')
