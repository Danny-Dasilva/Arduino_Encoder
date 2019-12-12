import serial
port = "/dev/ttyACM0"
baudRate = 9600
ser = serial.Serial(port=port, baudrate=baudRate)

encoder0 = 0
encoder1 = 0
token = 0
current_reading = ""

while ser.read() != b'a':
    pass

print("Exit")

while True:
    token = ser.read()

    if(token):
        if(token in [b'0', b'1', b'2', b'3', b'4', b'5', b'6', b'7', b'8', b'9', '-']):
            current_reading = current_reading + token.decode("utf-8")
        else:
            try:
                current_reading = int(current_reading)
                if(token == b'a'):
                    encoder0 = current_reading
                elif(token == b'b'):
                    encoder1 = current_reading
                print(encoder0, encoder1)
                current_reading = ""
            except:
                pass
