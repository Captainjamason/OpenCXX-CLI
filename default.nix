{pkgs ? import <nixpkgs> {} }:
pkgs.stdenv.mkDerivation {
    name = "opencxx-cli";
    src = ./out;

    installPhase = "
	cp -rv $src $out
    ";
}
