git fetch --all --recurse-submodules

git submodule deinit -f --all
git submodule update --init --recursive
