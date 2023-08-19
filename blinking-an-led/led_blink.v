module led_blink (
    input wire clk,       // System clock input
    output wire led       // LED output
);

reg [31:0] counter = 0;  // Counter to divide the clock frequency
reg toggle = 1;          // Signal to toggle the LED

always @(posedge clk) begin
    if (counter == 2) begin  // Approximately 1 Hz blink rate
        counter <= 0;
        toggle <= ~toggle;
    end else begin
        counter <= counter + 1;
    end
end

assign led = toggle;

endmodule

