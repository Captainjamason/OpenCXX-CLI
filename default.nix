{pkgs ? import <nixpkgs> {} }:
pkgs.stdenv.mkDerivation {
    name = "opencxx-cli";
    src = ./out;
    installPhase = "
        mkdir $out
        cp -rv $src/* $out
    ";
}