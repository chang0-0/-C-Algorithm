import json
import urllib.request
from bs4 import BeautifulSoup

def lambda_handler(event, context):
    url = "http://3.35.127.177:8000/catalog/?rdate=2020.11.26"
    soup = BeautifulSoup(urllib.request.urlopen(url).read(),"html.parser")
    td_tags = soup.find_all('td')
    result_list = []
    for i in td_tags:
        result_list.append(i.get_text())
    
    return {
        'statusCode': 200,
        'body': json.dumps(result_list)
    }
    
 
 