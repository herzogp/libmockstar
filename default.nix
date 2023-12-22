
let
  pkgs = import <nixpkgs> {};
in
  with pkgs;
  stdenv.mkDerivation {
    pname = "mockstar";
    version = "0.0.1";

    src = ./.;

    buildInputs = [
      cmake
    ];

    configurePhase = ''
      cmake -DBUILD_SHARED_LIBS=YES .
    '';

    # patchPhase = '' '';

    buildPhase = ''
      make mockstar
    '';

    # checkPhase = '' '';

    installPhase = ''
      mkdir -p $out/lib
      cp libmockstar.so $out/lib/libmockstar.so
      mkdir -p $out/include
      cp -pra include/* $out/include/
    '';

  }
