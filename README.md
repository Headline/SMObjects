# SMObjects
Psuedo-Objects in SourceMod as an Extension

## Installation
Download linux and windows binaries from the [build page](http://michaelwflaherty.com/SMObjects/)!

## Usage

```c
Handle handle = CreateObject();
SetObjectInt(handle, "something", 32);
PrintToServer("Some number: %i", GetObjectInt(handle, "something"));
```
## FAQ
**Couldn't I just use 'X' instead?**

Yes.

**Why should I use this?**

You probably shouldn't

**Why'd you make this?**

Because I need to learn C++
