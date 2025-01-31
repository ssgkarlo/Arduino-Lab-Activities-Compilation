from fastapi import FastAPI
import serial
import time

app = FastAPI()

# Global serial connection
arduino = None

@app.on_event("startup")
def startup_event():
    global arduino
    try:
        arduino = serial.Serial('COM4', 9600, timeout=1)  # Replace 'COM5' with your Arduino's port
        time.sleep(2)  # Allow Arduino to initialize
        print("Serial connection established.")
    except serial.SerialException as e:
        print(f"Error establishing serial connection: {e}")

@app.on_event("shutdown")
def shutdown_event():
    global arduino
    if arduino and arduino.is_open:
        arduino.close()
        print("Serial connection closed.")

@app.post("/led/on")
def turn_led_on():
    global arduino
    if arduino and arduino.is_open:
        arduino.write(b'1')  # Send the '1' signal to Arduino
        return {"status": "success", "message": "LED turned ON"}
    else:
        return {"status": "error", "message": "Serial connection is not open."}

@app.post("/led/off")
def turn_led_off():
    global arduino
    if arduino and arduino.is_open:
        arduino.write(b'0')  # Send the '0' signal to Arduino
        return {"status": "success", "message": "LED turned OFF"}
    else:
        return {"status": "error", "message": "Serial connection is not open."}
