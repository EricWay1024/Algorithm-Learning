from sys import argv
from os import mkdir, chdir
from shutil import copyfile
from sys import exit
from scraper import luogu_scraper, scraper

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
    if s == 'cpp' and problem_type == 'cg':
        copyfile(f'template/template_{problem_type}.{s}', f'{problem_type}/{problem}/{problem}.{s}')
    else:
        copyfile(f'template/template.{s}', f'{problem_type}/{problem}/{problem}.{s}')

with open(f'{problem_type}/{problem}/{problem}.cpp') as f:
    cppcode = f.read()

cppcode = cppcode.replace('freopen("", "r", stdin);', f'freopen("{problem}.in", "r", stdin);')

with open(f'{problem_type}/{problem}/{problem}.cpp', 'w') as f:
    f.write(cppcode)

# chdir(f'./{problem_type}/{problem}/')
print("Done! Enjoy coding!")

input_value = ''
oj = input("vJudge/Luogu/None auto download? [v/l/n]").strip().lower()
if oj in ['v', '']:
    input_value = scraper(problem, 'vjudge')
if oj == 'l':
    input_value = scraper(problem if len(problem) > 4 else 'P' + problem, 'luogu')
if oj in ['v', 'l', '']:
    with open(f'{problem_type}/{problem}/{problem}.in', 'w') as f:
        f.write(input_value)
    print("Done with input value:")
    print(input_value)
