
make_folders:
	mkdir -p build
	mkdir -p wasm

wasm: make_folders
	clang --target=wasm32 --no-standard-libraries -Wl,--export-table -Wl,--no-entry -Wl,--allow-undefined -Wl,--export=main -o build/kdtree.wasm kdtree.c -DPLATFORM_WEB
	cp build/kdtree.wasm wasm/

raylib: make_folders
	gcc -o build/raylib.out raylib/raylib_implementation.c kdtree.c -lraylib
