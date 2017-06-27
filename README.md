# SMObjects
Psuedo-Objects in SourceMod as an Extension

## Installation
Download linux and windows binaries from the [build page](http://michaelwflaherty.com/SMObjects/)!

## Usage

```c
Object obj = new Object();
obj.SetInt("something", 32); 
obj.SetCell("list", new ArrayList());
obj.GetCell("list").Push(40);

PrintToServer("Some number: %i", obj.GetInt("something"));

delete obj.GetCell("list"); // free ArrayList memory
delete object; // free Object memory
```
## FAQ
**Couldn't I just use 'X' instead?**

Yes.

**Why should I use this?**

You probably shouldn't

**Why'd you make this?**

Because I need to learn C++
