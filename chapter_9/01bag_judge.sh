#~/bin/zsh
pypy3 01bag_in_builder.py
./01bag_1.out < 01bag.in 
./01bag_2.out < 01bag.in 
./01bag_3.out < 01bag.in
diff ./01bag_1_.out ./01bag_2_.out
diff ./01bag_2_.out ./01bag_3_.out