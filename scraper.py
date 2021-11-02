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
    text_area_parsed = json.loads(text_area.text)['sections']
    # print(text_area_parsed)
    
    def get_sample_input_content(title):
        sample_input = next(filter(lambda x: x['title'] == title, text_area_parsed))
        sample_input_content = BeautifulSoup(sample_input['value']['content'], 'html.parser')
        
        if title == 'Sample Input':
            return sample_input_content.text
        
        elif title == 'Examples':
            input_code = sample_input_content.find('pre')
            for br in input_code.find_all('br'):
                br.replace_with('\n')
            return input_code.text
    
    def helper(title):
        try:
            return get_sample_input_content(title)
        except StopIteration:
            return None
    
    for title in ["Examples", 'Sample Input']:
        ans = helper(title)
        if ans is not None:
            return ans
    raise RuntimeError('Unknown web page format.')

def uva_scraper(problem_id):
    pass

def scraper(problem_id, oj):
    try:
        return vjudge_scraper(problem_id)
    except:
        pass

    try:
        return luogu_scraper(problem_id)
    except:
        pass

    raise RuntimeError('No scraper worked.')
    # if (oj == 'luogu'):
    #     return luogu_scraper(problem_id)
    # else:
    #     return vjudge_scraper(problem_id)

if __name__ == '__main__':
    print(vjudge_scraper('SGU-325'))