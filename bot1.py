import pyautogui
import webbrowser
import time
import os
import fnmatch
import shutil

pyautogui.moveTo(427,398, duration=0.25)
pyautogui.click(427,398, button='left',duration=0.25)
a=0.25
b=a*2
c=a/2
pyautogui.press('space')

pyautogui.moveTo(412, 275, duration=0.25)
pyautogui.click(412, 275,button='left',duration=0.25)
time.sleep(0.25)
pyautogui.moveTo(478,163, duration=0.25)
pyautogui.click(478,163,button='left',duration=0.25)

time.sleep(a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.press('tab')
time.sleep(a)

pyautogui.write('160921', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('cola', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('fixar objetos', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('250', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('ml', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('5', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('5', interval=a)
pyautogui.press('tab')
time.sleep(a)
pyautogui.write('estoque', interval=a)

pyautogui.moveTo(476,663, duration=0.25)
pyautogui.click(476,663,button='left',duration=0.25)

time.sleep(b)
pyautogui.press('space')
time.sleep(a)
pyautogui.press('space')

pyautogui.moveTo(654, 219, duration=0.25)
pyautogui.click(654, 219,button='left',duration=0.25)

time.sleep(b)
pyautogui.press('space')
time.sleep(a)
pyautogui.press('space')
time.sleep(a)

aux=0
while aux<30:
    aux=aux+1
    time.sleep(c)
    pyautogui.press('up')

pyautogui.moveTo(74, 171, duration=0.25)
pyautogui.click(74, 171,button='left',duration=0.25)

time.sleep(b)
pyautogui.press('space')
time.sleep(a)
pyautogui.press('space')

pyautogui.moveTo(641,509, duration=0.25)
pyautogui.click(641,509,button='left',duration=0.25)

time.sleep(b)

pyautogui.moveTo(449,403, duration=0.25)
pyautogui.click(449,403,button='left',duration=0.25)

time.sleep(b)

pyautogui.moveTo(563,212, duration=0.25)
pyautogui.click(563,212,button='left',duration=0.25)

aux=0
while aux<25:
    aux=aux+1
    time.sleep(c)
    pyautogui.press('tab')
    
pyautogui.press('down')
time.sleep(c)
pyautogui.press('down')
pyautogui.press('enter')
time.sleep(c)
pyautogui.press('tab')
pyautogui.write('100', interval=a)
pyautogui.press('tab')
time.sleep(c)
pyautogui.press('enter')

time.sleep(a)

pyautogui.moveTo(448,400, duration=0.25)
pyautogui.click(448,400,button='left',duration=0.25)

time.sleep(a)

aux=0
while aux<25:
    aux=aux+1
    time.sleep(c)
    pyautogui.press('tab')
