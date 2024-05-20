module reg7 (
input	[6:0] ed,
input	eck,
input	era,
input	ers,
input	es,
input   eena,
output  [6:0] sq);


    ffd_rsync meu_ff_0		(	.sq(sq[0]), 
							.ed(ed[0]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));
    
    ffd_rsync meu_ff_1		(	.sq(sq[1]), 
							.ed(ed[1]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));

        ffd_rsync meu_ff_2		(	.sq(sq[2]), 
							.ed(ed[2]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));

        ffd_rsync meu_ff_3		(	.sq(sq[3]), 
							.ed(ed[3]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));

        ffd_rsync meu_ff_4		(	.sq(sq[4]), 
							.ed(ed[4]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));
    
	        ffd_rsync meu_ff_5		(	.sq(sq[5]), 
							.ed(ed[5]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));

	        ffd_rsync meu_ff_6		(	.sq(sq[6]), 
							.ed(ed[6]), 
							.eck(eck), 
							.er_async(era), 
							.er_sync(ers),
							.es(es), 
							.eena(eena));

endmodule

