# Corewar

Core War was inspired by a malicious virus written in the 80’s. To deal with the self-replicating virus, a white hat hacker invented Reaper. It was a virus designed to spread and eliminate the malware. He fought fire with fire.

This inspired A. K. Dewdney to coin the idea for Core War.

The idea was simple. You compete by designing viruses to overtake a computer. You win by protecting your own program and overwriting your opponent's programs. This is all happening on a virtual computer. Think, a simple computer within your computer.

This is what is looks like in action:

![Corewar](https://github.com/ayundina/corewar/blob/master/resources/gif/191115_1702_corewar.gif)

**1. Game board.**<br/><br/>
The memory of our virtual computer. It’s represented in a 64 X 64 grid of bytes. Every byte, the pairs of numbers or letters, are represented in hexadecimal. Each hexadecimal has the value of a digit, from 0 to 255. The values represent commands and command's arguments. There are 16 commands.<br/> 
**2. Players.**<br/><br/>
Small programs represented in different colors. The white parts have blank memory.<br/>
**3. Cursors.**<br/><br/>
The moving parts with inverted color. They read from the game board.
The cursors have a couple of features. They can jump on the game board, store and write values, and clone themselves. The cursors belong to no-one, they just read from the game board.When the game starts, all players have one cursor at the beginning of their program. The game advances as the cursors read the commands stored in their programs. If a cursor ends up on a faulty command or a blank memory, it moves to the next byte.
<br/>
<br/>
**Player wins if he is the last one to declare himself alive**<br/>
If a cursor reads a players life command from the game board, it stays alive for one round. Every game round is measured in cycles. "Cycles to die" determine how much each cursor can read from the game board within one round. Cycles to die gradually decrese, until it reaches zero. At that point game ends and a winner is announced.

