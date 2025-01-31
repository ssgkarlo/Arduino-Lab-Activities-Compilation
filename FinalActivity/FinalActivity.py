import serial
import time
import requests

# Replace with your Arduino's port
arduino_port = "COM3"  # Example: "/dev/ttyUSB0" for Linux/Mac
baud_rate = 9600       # Match the baud rate in Arduino code

# API Endpoint
api_url = "http://172.20.10.2:8000/final_lab"

try:
    # Establish serial connection
    ser = serial.Serial(arduino_port, baud_rate)
    time.sleep(2)  # Wait for the connection to initialize
    print("Connection established. Waiting for button clicks...")
except serial.SerialException as e:
    print(f"Failed to open serial port {arduino_port}: {e}")
    exit(1)

try:
    while True:
        if ser.in_waiting > 0:  # Check if data is available
            data = ser.readline().decode('utf-8').strip()  # Read and decode data

            if data == "group3_on":  # Button pressed
                print("Button Pressed")
                params = {"groupName": "group3_on"}
                response = requests.get(api_url, params=params, json={"status": "success", "message": "group3_on"})
                
                if response.status_code == 200:
                    print("API called successfully!")
                else:
                    print(f"API call failed with status code: {response.status_code}")

            elif data == "group3_off":  # Button not pressed
                print("Button Not Pressed")
                params = {"groupName": "group3_off"}
                response = requests.get(api_url, params=params, json={"status": "success", "message": "group3_off"})
                
                if response.status_code == 200:
                    print("API called successfully!")
                else:
                    print(f"API call failed with status code: {response.status_code}")

except KeyboardInterrupt:
    print("\nExiting...")

finally:
    ser.close()  # Close the serial connection
    print("Serial connection closed.")