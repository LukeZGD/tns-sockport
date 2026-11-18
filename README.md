# TNS Sockport

An updated version of TotallyNotSpyware with sockport2 exploit and updated bootstrap.

- Replaced v0rtex with sockport2 for better reliability (except for A9(X) devices where v0rtex is still used)
- Installs [Melder](http://repo.k0.tel/depictions/com.koutsie.melder.html) instead of Cydia on initial installation
- Disabled Meridian, A10 users can use [MeridianFix](https://github.com/LukeZGD/MeridianFix) instead

[**[ Live version at lukezgd.github.io/tns-sockport ]**](https://lukezgd.github.io/tns-sockport)

This program is definitely not spyware.
Run it on your 64-bit iOS device as soon as possible.
Your compliance will be rewarded.

### Repo structure & building

Frontend and WebKit exploit are in `/root`.
Kernel exploit is in `/glue`.
Post-exploitation is in `/glue/dep`.

DoubleH3lix and Meridian can be built independently into static libraries with `make headless` and `make all` respectively, in their directories.
Those are then used to build the `payload` in `/glue`, which is the binary that is ran from JIT after the WebKit exploit. Can be built with just a `make`, and will build all dependencies as needed.
And that is all finally strung together with the WebKit exploit by running `make` in `/root`, which will again build dependencies as needed.

### Patch

We originally wanted to backport the WebKit patch to 10.x, but ultimately gave up.

See `/patch` for details, but the gist is:
One part of the WebKit bug was incorrect predictions in `JSC::DFG::clobberize`, which is basically a huge switch-case. The fix for that was to re-route some values to blocks that are already used for other values.
On the versions we checked, the compiler had generated jump tables for that, so our idea would've been to just find and patch all those jump tables, since the correct code would already be present.
The issue is that the values that everything depends on have changed hundreds of times over the lifetime of iOS 10 (yes, much more frequently than there have been iOS releases), and there seem to be no landmarks anywhere nearby in code, so it's virtually impossible for us to determine which values to patch. :(

### Credits

- The final ~~countdown~~ product: [Jake Blair](https://twitter.com/JakeBlair420)
- The entire frontend, website, etc.: [FoxletFox](https://twitter.com/FoxletFox)
- WebKit exploit: [Niklas Baumstark](https://twitter.com/_niklasb/), with part of [Samuel Groß](https://twitter.com/5aelo/)' code patched in.
- Everyone credited for the [DoubleH3lix](https://github.com/Siguza/doubleH3lix) and [Meridian](https://github.com/PsychoTea/MeridianJB) jailbreaks.
