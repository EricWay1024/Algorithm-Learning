def luogu_scraper(problem_id):
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

def vjudge_scraper(problem_id):
    import requests
    from bs4 import BeautifulSoup
    import json

    headers = {
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:84.0) Gecko/20100101 Firefox/84.0',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
        'Accept-Language': 'en-US,en;q=0.5',
        'Connection': 'keep-alive',
        'Upgrade-Insecure-Requests': '1',
        'Cache-Control': 'max-age=0',
        'TE': 'Trailers',
    }
    response = requests.get(f'https://vjudge.net/problem/{problem_id}', headers=headers)
    parsed_response = BeautifulSoup(response.text, 'html.parser')
    list_item = parsed_response.find(attrs={'class', 'list-group-item'})
    x = list_item.find('a')
    data_id = x['data-id']
    data_version = x['data-version']
    response = requests.get(f'https://vjudge.net/problem/description/{data_id}?{data_version}')
    parsed_response = BeautifulSoup(response.text, 'html.parser')
    text_area = parsed_response.find('textarea')
    text_area_parsed = json.loads(text_area.text)
    sample_input = next(filter(lambda x: x['title'] == 'Sample Input', text_area_parsed['sections']))
    sample_input_content = BeautifulSoup(sample_input['value']['content'], 'html.parser')
    return sample_input_content.text

def scraper(problem_id, oj):
    if (oj == 'luogu'):
        return luogu_scraper(problem_id)
    else:
        return vjudge_scraper(problem_id)