import pyautogui
import webbrowser
import time
import os
import fnmatch
import shutil

#MOSTRA A POSICAO DO MOUSE NA TELA
a=pyautogui.position()
print(a)



#MOVE O MOUSE PARA A POSICAO 443,383 E FAZ UM CLICK DE 0.25 SEGUNDOS
#pyautogui.moveTo(posicao X = 80,posicao Y = 738, duration=0.25)
pyautogui.moveTo(117, 105, duration=0.25)
pyautogui.click(117, 105, button='left',duration=0.25)
a=0
while a<92:
    pyautogui.keyDown("'")
    time.sleep(0.25)
    pyautogui.keyDown('$')
    time.sleep(0.25)
    #pyautogui.write('nfst2', interval=0.25)
    pyautogui.hotkey('ctrl','right')
    time.sleep(0.25)
    pyautogui.keyDown("'")
    time.sleep(0.25)
    pyautogui.keyDown('right')
    time.sleep(0.25)
    pyautogui.hotkey('ctrl','right')
    pyautogui.hotkey('ctrl','left')
    a=a+1

