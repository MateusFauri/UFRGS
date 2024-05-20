module duas_chaves(
    input in2,
    input in1,
    input in0,
    output a,
    output b,
    output c,
    output d,
    output e,
    output f,
    output g
    );

wire nin2, nin1, nin0;
not(nin1, in1);
not(nin0, in0);
not(nin2, in2);

wire min0, min1, min2, min3, min4, min5, min6, min7;
wire max0, max1, max3, max5;
and(min0, nin2, nin1, nin0); //mintermo 0
and(min1, nin2, nin1, in0); //mintermo 1
and(min2, nin2, in1, nin0); //mintermo 2
and(min3, nin2, in1, in0); //mintermo 3
and(min4, in2, nin1, nin0);
and(min5, in2, nin1, in0);
and(min6, in2, in1, nin0);
and(min7, in2, in1, in0);

not(max0, min0);
not(max1, min1);
not(max5, min5);
not(max3, min3);

buf(a, max0);
buf(b, max1);
buf(c, max5);
buf(d, max0);
and(e, max0, max3);
and(f, max0, max5);
or(g, min1, min3, min4, min5);

endmodule
