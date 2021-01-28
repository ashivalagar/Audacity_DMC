#!/usr/bin/env.python3
import serial
import time
from flask import Flask, request

app = Flask(__name__)

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

if __name__ == "__main__":
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.flush()
    app.run(threaded=True)