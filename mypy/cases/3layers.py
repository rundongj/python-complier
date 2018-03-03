def a():
  x = 1
  print 1
  def b():
    if x>0:
      y=2
    print 2
    def c():
      z=3
      print 3
      if z>1:
        print y
        if x>1:
          print z
        else:
          print x

    c()
  b()


a()
