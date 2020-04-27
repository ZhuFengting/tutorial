from bs4 import BeautifulSoup
import requests
from  requests.exceptions import RequestException
import re
import json

def get_one_page(url):
    headers = {
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36"
    }
    try:
        responce = requests.get(url, headers=headers)
        if responce.status_code == 200:
            return responce.text
        return None
    except RequestException:
        return None

def parse_one_page(html):
    pattern = re.compile('<dd>.*?board-index.*?>(\d+)</i>.*?title="(.*?)"',re.S)
    result = re.findall( pattern, html)
    for item in result:
        yield {
            "index": item[0],
            "titel": item[1]
        }
def write_to_file(content):
    with open("result.text","a",encoding="utf-8") as f:
        f.write(json.dumps(content,ensure_ascii=False)+"\n")
        f.close()

def main(offset):
    url = "https://maoyan.com/board/4?offset="+str(offset)
    html = get_one_page(url)
    for result in parse_one_page(html):
        write_to_file(result)
        print(result)

if __name__ == "__main__":
    for i in range(10):
        main(10*i)



