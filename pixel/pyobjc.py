import pyautogui
from pyautogui import hotkey
from sys import stderr, stdout
from time import time as ts

import Quartz.CoreGraphics as CG

class PixelPyObjC:
    def __init__(self, x, y):
        self.x_ = x
        self.y_ = y
        self.region_ = CG.CGRectMake(x, y, 1, 1)

    def pixel(self):
        screen_capture = CG.CGWindowListCreateImage(self.region_,
                                                    CG.kCGWindowListOptionOnScreenOnly,
                                                    CG.kCGNullWindowID,
                                                    CG.kCGWindowImageDefault)
        pixel_data = CG.CGDataProviderCopyData(CG.CGImageGetDataProvider(screen_capture))
        data = bytearray(pixel_data)
        return '#{:02x}{:02x}{:02x}'.format(data[2], data[1], data[0])


ppoc = PixelPyObjC(16, 16)


def solution(x, y):
    tic = ts()
    res = ppoc.pixel()
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
