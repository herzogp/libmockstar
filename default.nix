
let
  pkgs = import <nixpkgs> {};
in
  with pkgs;
  stdenv.mkDerivation {
    pname = "mockstar";
    version = "0.0.2";

    src = ./.;

    buildInputs = [
      cmake
    ];

    configurePhase = ''
      cmake -DBUILD_SHARED_LIBS=YES .
    '';

    # patchPhase = '' '';

    buildPhase = ''
      #env
      make mockstar
      #ls -lR 
    '';

    # checkPhase = '' '';

    installPhase = ''
      mkdir -p $out/lib
      cp libmockstar.so $out/lib/libmockstar.so
      mkdir -p $out/include
      cp -pra include/* $out/include/
      rm $out/include/config.h
      rm -rf $out/include/mockstar/internal
    '';

  }
