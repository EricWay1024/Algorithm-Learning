from sys import argv
from os import mkdir, chdir
from shutil import copyfile
from sys import exit

def scraper(problem_id):
    import requests
    from bs4 import BeautifulSoup

    headers = {
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:84.0) Gecko/20100101 Firefox/84.0',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
        'Accept-Language': 'en-US,en;q=0.5',
        'Connection': 'keep-alive',
        'Upgrade-Insecure-Requests': '1',
        'Cache-Control': 'max-age=0',
        'TE': 'Trailers',
    }

    response = requests.get(f'https://www.luogu.com.cn/problem/{problem_id}', headers=headers)

    parsed_response = BeautifulSoup(response.text, 'html.parser')
    input_value = parsed_response.find('code').text
    return input_value


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

with open(f'{problem_type}/{problem}/{problem}.cpp') as f:
    cppcode = f.read()

cppcode = cppcode.replace('freopen("", "r", stdin);', f'freopen("{problem}.in", "r", stdin);')

with open(f'{problem_type}/{problem}/{problem}.cpp', 'w') as f:
    f.write(cppcode)

# chdir(f'./{problem_type}/{problem}/')
print("Done! Enjoy coding!")

if input("Luogu auto download? [Y/n]") not in ['n', 'N']:
    input_value = scraper(problem if len(problem) > 4 else 'P' + problem)
    with open(f'{problem_type}/{problem}/{problem}.in', 'w') as f:
        f.write(input_value)
    print("Done with input value:")
    print(input_value)