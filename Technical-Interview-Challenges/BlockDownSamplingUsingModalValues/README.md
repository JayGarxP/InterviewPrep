# C++  Image Downsampling with Boost Library

*Weekend long take home assignment from ivy-league partnered triple A game dev*

I was given the .pdf file assignment about block downsampling, and implemented a solution for 
the first few block dimensions, didn't get to the higher dimensions in time.

They were looking for someone who would just use a Python libary - the right tools for the job, like Python Image Processing Libary
and call it with C++, not just grind their way through with pure C++ (I literally used valgrind to find memory leaks haha).

Pretty cool/fun anyway, by doing it the hard way I learned a lot about image processing and stumbled across cool code snippets and stories from across the internet.
Like this: https://stackoverflow.com/a/150811/3663273
Interesting Stack Overflow QA about heap fragmentation in medical image processing. 
Similar memory efficiency / leak / slowdown problems occur in RTS video games where many enemy units with different enough
underlying objects, don't fit nicely into same-sized buffers are being spawned/despawned at different times. 
Lots of little scraps of unused memory can be left behind that are too small to use on their own but have no easy way to recombine into larger free blocks.
Some solutions are to rely on the OS to manage memory, use your own custom memory allocator like Doug Mallea cmalloc.


By using machine learning on lots of xrays / MRIs, algos can find things that doctors miss and catch health problems early!
Compressing the images and feeding them uniformly in parrallel processes makes the process of building up the machine's knowledge base faster.
The actual AI machine learning algos and techniques are outside my pay grade! Can't help you there.
