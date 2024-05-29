import requests
def send_message(message):
    url = "https://bd5e6aca3032e2.lhr.life/chat"
    data = {'text': message}
    response = requests.post(url, json=data)
    if response.status_code == 200:
        return response.text
    else:
        return f"Error: {response.status_code} - {response.reason}"
def main():
    print("Press 'q' at any time to exit the chat.")
    while True:
        message = input("\n\nYou: ")
        if message.lower() in ['exit', 'quit', 'q']:
            print("Exiting chat.")
            break
        try:
            print("Bot đang trả lời...", end="", flush=True)
            print()
            response = send_message(message=message)
            print(response)
        except Exception as e:
            print(f"An error occurred: {e}")
if __name__ == "__main__":
    main()
