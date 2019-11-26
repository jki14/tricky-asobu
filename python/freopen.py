import sys

def main():
  sys.stdin = open('freopen.in', 'r')
  sys.stdout = open('freopen.out', 'w')
  msg = raw_input()
  print msg
  sys.stdin.close()
  sys.stdout.close()

if __name__ == '__main__':
  main()
