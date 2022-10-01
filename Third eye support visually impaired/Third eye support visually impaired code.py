from machine import Pin,Timer,PWM
import utime

timer = Timer()
trigger = Pin(15, Pin.OUT)
echo = Pin(13, Pin.IN)
led = Pin(16, Pin.OUT)
speaker = PWM(Pin(19,Pin.OUT))
distance = 0

def get_distance(timer):
    global distance
    trigger.high()
    utime.sleep(0.00001)
    trigger.low()
    
    while echo.value() == 0:
        start = utime.ticks_us()
    while echo.value() ==1:
        stop = utime.ticks_us()
        
    duration = stop - start
    distance = (duration * 0.0343 / 2)
    print("Distance:",distance,"cm:")
    return distance
timer.init(freq=1,mode=Timer.PERIODIC, callback=get_distance)

while True:
    
    if distance < 10:
        led.value(1)
        speaker.duty_u16(5000)
        speaker.freq(3000)
        utime.sleep(1)
        speaker.duty_u16(0)
        utime.sleep(distance/1000)
        speaker.duty_u16(0)
    else:
        led.value(0)
