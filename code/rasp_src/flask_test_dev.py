#!/usr/bin/env.python3
import serial
from flask import Flask, request
import threading
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

def serial_logger():
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)

@app.route('/open', methods=['GET'])
def open():
    ser.write(b"1")
    line = ser.readline().decode('utf-8').rstrip()
    return line

@app.route('/close', methods=['GET'])
def close():
    ser.write(b"2")
    line = ser.readline().decode('utf-8').rstrip()
    return line

@app.route('/stop', methods=['GET'])
def stop():
    ser.write(b"3")
    line = ser.readline().decode('utf-8').rstrip()
    return line

@app.route('/forward', methods=['GET'])
def forward():
    ser.write(b"4")
    line = ser.readline().decode('utf-8').rstrip()
    return line

@app.route('/test', methods=['GET'])
def test():
    return "Live"

if __name__ == "__main__":
    ser = serial.Serial('/dev/ttyACM1', 115200, timeout=1)
    ser.flush()
    flask_thread = threading.Thread(target=app.run(threaded=True))
    flask_thread.start()
    