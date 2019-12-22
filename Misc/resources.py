# Set rotary servo angle between 0 and 90 degrees
def SetAngle(angle):
    if angle < 0 or angle > 90:
        return False
    else:
        duty = angle / 18 + 2
        GPIO.output(PWMpin, True)
        p.ChangeDutyCycle(duty)
        sleep(1)
        GPIO.output(PWMpin, False)
        p.ChangeDutyCycle(0)
        return True

# Set ilnear servo angle between 0 and 20mm
def SetPosition(position, PWMpin, p):
    if position < 0 or position > 20:
        return False
    else:
        duty = mapVal(position, (0, 20), (3.6, 9.2))
        GPIO.output(PWMpin, True)
        p.ChangeDutyCycle(duty)
        sleep(1)
        GPIO.output(PWMpin, False)
        p.ChangeDutyCycle(0)
        return True

# Function to map number from one range to another using linear scale
def mapVal(val, fromRange, toRange):
    return ((float(val) - fromRange[0]) / (fromRange[1] - fromRange[0])) * (toRange[1] - toRange[0]) + toRange[0]