#include <stdio.h>
#include <math.h>

int main(void)
{
 //gnuplotを呼びだす
 FILE *gid;
 gid = _popen("C:/gnuplot/bin/gnuplot.exe", "w");

 // 範囲の指定
 fprintf(gid, "set xrange [0:5]\n"); 
 fprintf(gid, "set yrange [0:7]\n");

 //グラフを描く
 fprintf(gid, "plot '2-3.dat' title 'もとのデータ', 0.5+1.2*x title 'フィッティング';\n");

 //guplotの後処理
 fflush(gid);
 fprintf(gid, "pause mouse\n");
}