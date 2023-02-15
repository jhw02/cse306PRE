{ pkgs }: {
	deps = [
		pkgs.emacs
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}