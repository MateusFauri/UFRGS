module add (
input	[7:0] a,
input	[7:0] b,
input   subtrator,
output	[7:0] cout
output  [7:0] s);

    wire [7:0] fio;
    wire [7:0] fiob;

    xor(fiob [0], b [0], subtrator);
    xor(fiob [1], b [1], subtrator);
    xor(fiob [2], b [2], subtrator);
    xor(fiob [3], b [3], subtrator);
    xor(fiob [4], b [4], subtrator);
    xor(fiob [5], b [5], subtrator);
    xor(fiob [6], b [6], subtrator);
    xor(fiob [7], b [7], subtrator);

    full_adder bit_0(   .a(a[0]),
                        .b(fiob[0]),
                        .cin(subtrator),
                        .s(s[0]),
                        .cout(fio[0]));

    full_adder bit_1(   .a(a[1]),
                        .b(fiob[1]),
                        .cin(subtrator),
                        .s(s[1]),
                        .cout(fio[1]));

 
    full_adder bit_2(   .a(a[2]),
                        .b(fiob[2]),
                        .cin(subtrator),
                        .s(s[2]),
                        .cout(fio[2]));

    full_adder bit_3(   .a(a[3]),
                        .b(fiob[3]),
                        .cin(subtrator),
                        .s(s[3]),
                        .cout(fio[3]));
               
    full_adder bit_4(   .a(a[4]),
                        .b(fiob[4]),
                        .cin(subtrator),
                        .s(s[4]),
                        .cout(fio[4]));

    full_adder bit_5(   .a(a[5]),
                        .b(fiob[5]),
                        .cin(subtrator),
                        .s(s[5]),
                        .cout(fio[5]));

    full_adder bit_6(   .a(a[6]),
                        .b(fiob[6]),
                        .cin(subtrator),
                        .s(s[6]),
                        .cout(fio[6]));

    full_adder bit_7(   .a(a[7]),
                        .b(fiob[7]),
                        .cin(subtrator),
                        .s(s[7]),
                        .cout(fio[7]));
endmodule

