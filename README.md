# Lem-in
graph-traversal project for school 21 (42 Moscow)

This is the Lem-in project done by me and my teammate Cmissy at school 21 (42 Moscow).

The goal of the project is to get ants (packages?) from start to finish over a graph via the shortest roots possible, with no overlapping, no traffic jams.

The graphs in question are not weighted. You simultaneusly move all possible ants in one "move", and the final criteria was to make as few moves as possible.

I attached the map generator.

First run Make.

Then, the project can be visualized (if your machine allows for the visualizer to work) by running the following:

./generator --flow-thousand | ./lem-in | ./bonus/visual
