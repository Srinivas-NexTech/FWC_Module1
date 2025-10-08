module helloworldfpga (    
             
                input reset,
                output blink,
                output redled,
                output blueled,
                output greenled
              
                );



assign blink= reset ? 1'd0: 1'd1;  //reset the input 
assign blueled= reset ? 1'd0: 1'd1;
//assign redled= reset ? 1'd0: 1'd1;

endmodule  
