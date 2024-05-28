"""

Đầu tiên cần cài đặt thư viện bằng lệnh:
pip install google-generativeai
"""

import google.generativeai as genai

def ai(api_key, history):
    genai.configure(api_key=api_key)

    generation_config = {
        "temperature": 0.8,
        "top_p": 0.95,
        "top_k": 0,
        "max_output_tokens": 8192,
    }

    safety_settings = [
        {"category": "HARM_CATEGORY_HARASSMENT", "threshold": "BLOCK_MEDIUM_AND_ABOVE"},
        {"category": "HARM_CATEGORY_HATE_SPEECH", "threshold": "BLOCK_MEDIUM_AND_ABOVE"},
        {"category": "HARM_CATEGORY_SEXUALLY_EXPLICIT", "threshold": "BLOCK_MEDIUM_AND_ABOVE"},
        {"category": "HARM_CATEGORY_DANGEROUS_CONTENT", "threshold": "BLOCK_MEDIUM_AND_ABOVE"},
    ]

    model = genai.GenerativeModel(
        model_name="gemini-1.5-pro-latest",
        generation_config=generation_config,
        safety_settings=safety_settings,
    )

    print("AI: Hello! 👋 How can I help you today?")

    while True:
        user_input = input("You: ")
        
        history.append({"role": "user", "parts": [user_input]})
        
        convo = model.start_chat(history=history)
        convo.send_message(user_input)
        response = convo.last.text
        
        print("AI:", response)
        
        history.append({"role": "model", "parts": [response]})

history = []
api_keys = [
    "AIzaSyBWloAlNFD5PWU55oXzpA1YVCJqdEUlkt4", # Đây là key của t,
    "Tự thêm key của m vào đây, thêm nhiều vào để nó hết giới hạn trong 1 phút thì nó tự next key khác."
]

for key in api_keys:
    try:
        ai(key, history)
    except Exception as e:
        print("Failed with API key:", key)
        print("Error:", str(e))
        continue