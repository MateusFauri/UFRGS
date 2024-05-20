module cc_saida (
input	[6:0] a,
output	[6:0] s);

buf(s[0], a[0]);
buf(s[1], a[1]);
buf(s[2], a[2]);
buf(s[3], a[3]);
buf(s[4], a[4]);
buf(s[5], a[5]);
buf(s[6], a[6]);

endmodule

