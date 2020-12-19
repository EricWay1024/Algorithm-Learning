from sys import argv
from os import mkdir, chdir
from shutil import copyfile

from sys import exit
problem_type = argv[1]
problem = argv[2]
a = input(f"Type = {problem_type}, Name = {problem}. Continue? [Y/n]")
if a in ['n', 'N']:
    exit(0)

try:
    mkdir(f'{problem_type}')
except FileExistsError:
    pass

try:
    mkdir(f'{problem_type}/{problem}')
except FileExistsError:
    pass

for s in ['cpp', 'in']:
    copyfile(f'template/template.{s}', f'{problem_type}/{problem}/{problem}.{s}')

# chdir(f'./{problem_type}/{problem}/')
print("Done! Enjoy coding!")