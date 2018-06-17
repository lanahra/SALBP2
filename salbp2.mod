param n >= 0;
/* number of tasks */

set N := 1..n;
/* set of tasks */

param m >= 0;
/* number of workstations */

set S := 1..m;
/* set of workstations */

set A within N cross N;
/* precedence graph */

param t{i in N}, integer, >= 0;
/* execution time of each task */

var x{s in S, i in N}, binary;
/* 1 if task n is allocated to workstation s, 0 otherwise */

var c;
/* cycle time */

minimize time: c;

s.t. cycle{s in S}: sum{i in N} t[i] * x[s, i] <= c;
/* minimize cycle time */

s.t. task{i in N}: sum{s in S} x[s, i] = 1;
/* ensure that every task is assigned to a workstation */

s.t. precedence{(i, j) in A, r in S}: x[r, j] <= sum{s in S: s <= r} x[s, i];
/* precedence constraints */

end;
