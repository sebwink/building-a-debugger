build: build@debug
	@#

build@%: configure@%
	env -u MAKELEVEL cmake --build --preset $*

configure: configure@debug
	@#

configure@%: vcpkg/bootstrap-vcpkg.sh
	env -u MAKELEVEL cmake -S . --preset $*
	ln -sf build/$*/compile_commands.json compile_commands.json

vcpkg/bootstrap-vcpkg.sh:
	git submodule update --init --remote
	git submodule update 
	cd vcpkg && ./bootstrap-vcpkg.sh

clean@%:
	rm -rf build/$*

test: test@debug
	@#

test@%: build@%
	cd build/$* && ctest --output-on-failure

docs@%: build@debug
	mkdir -p build/docs/$*
	cd docs/doxygen/$* && doxygen

docs: docs@dev
	@#

clean:
	rm -rf build compile_commands.json
