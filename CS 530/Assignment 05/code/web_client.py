# web_client.py
# Joseph Gareri
# 00099183
# jgareri@my.athens.edu
# Asg 05
# Utilized large language model for troubleshooting/refactoring

import requests

def make_get_request(url):
    try:
        response = requests.get(url)
        response.raise_for_status()
        
        data = response.json()
        for item in data:
            print(f"Title: {item.get('title')}")
            
    except requests.exceptions.HTTPError as http_err:
        print(f"HTTP error occurred: {http_err}")
    except Exception as err:
        print(f"Other error occurred: {err}")

def make_post_request(url, data):
    try:
        response = requests.post(url, json=data)
        response.raise_for_status()
        
        print("POST request successful.")
        print(f"Response content: {response.json()}")
        
    except requests.exceptions.HTTPError as http_err:
        print(f"HTTP error occurred: {http_err}")
    except Exception as err:
        print(f"Other error occurred: {err}")

if __name__ == "__main__":
    print("----- GET Request -----")
    get_url = 'https://jsonplaceholder.typicode.com/posts'
    make_get_request(get_url)
    
    print("----- POST Request -----")
    post_url = 'https://jsonplaceholder.typicode.com/posts'

    sample_data = {
        "title": "My New Post",
        "body": "This is the content of my new post.",
        "userId": 1
    }
    make_post_request(post_url, sample_data)