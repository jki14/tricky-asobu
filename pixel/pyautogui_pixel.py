import pyautogui
from pyautogui import hotkey, pixel
from sys import stdout
from time import time as ts

def solution(x, y):
    tic = ts()
    res = '%02x%02x%02x' % pixel(x, y)
    tac = ts()
    stdout.write('pixel (PAUSE = %.6f) (RES = %s): %.6f\n' % (pyautogui.PAUSE, res, tac - tic))
    tic = ts()
    hotkey('num0')
    tac = ts()
    stdout.write('hotkey (PAUSE = %.6f): %.6f\n' % (pyautogui.PAUSE, tac - tic))

def main():
    for i in range(8):
        solution(16, 16)
    pyautogui.PAUSE = 0
    for i in range(8):
        solution(16, 16)


if __name__ == '__main__':
    main()
