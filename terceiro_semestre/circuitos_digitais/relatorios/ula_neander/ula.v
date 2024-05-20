module reg2 (
input	[7:0] a,
input   [7:0] b,
input	subtrai,
input	[1:0] s,
input   cin,
output  [7:0] cout,
output  [7:0] sum,
output  [7:0] fi);



    add ula_add(   .a(a),
                    .b(b),
                    .subtrator(subtrai),
                    .s(sum),
                    .cout(cout)
                    );

    mux41 ula_mux(  .sel(s),
                    .a(a),
                    .b(b),
                    .sum(sum),
                    .s(fi));
    );

endmodule