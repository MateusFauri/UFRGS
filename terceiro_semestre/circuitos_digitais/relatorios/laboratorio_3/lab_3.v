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
wire a1,b1,c1,d1,e1,f1;

and(min0, nin2, nin1, nin0);    // !a * !b * !c
and(min1, nin2, nin1, in0);     // !a * !b *  c
and(min2, nin2, in1, nin0);     // !a *  b * !c
and(min3, nin2, in1, in0);      // !a *  b *  c
and(min4, in2, nin1, nin0);     //  a * !b * !c
and(min5, in2, nin1, in0);      //  a * !b *  c
and(min6, in2, in1, nin0);      //  a *  b * !c
and(min7, in2, in1, in0);       //  a *  b *  c


or(a1,min1,min2,min3,min4);
or(a,a1,min5,min6,min7);

or(b1,min0,min2,min3,min4);
or(b,b1, min5,min6,min7);

or(c1,min0,min1,min2,min3);
or(c,c1,min4,min6,min7);

or(d1,min1,min2,min3,min4);
or(d,d1,min5,min6,min7);

or(e1, min1, min2, min4, min5);
or(e, e1, min6,min7);

or(f1, min1,min2,min3,min4);
or(f, f1, min6,min7);

or(g, min1, min3, min4, min5);

endmodule