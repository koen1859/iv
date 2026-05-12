{
  description = "C++ flake";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = nixpkgs.legacyPackages.${system};
      nativeBuildInputs = with pkgs; [cmake pkg-config SDL2 stb];
      iv = pkgs.stdenv.mkDerivation {
        pname = "iv";
        version = "0.0.1";
        src = ./.;
        inherit nativeBuildInputs;
        installPhase = ''
          mkdir -p $out/bin
          cp iv $out/bin
        '';
      };
    in {
      packages.iv = iv;
      devShells.default = pkgs.mkShell {
        buildInputs = nativeBuildInputs ++ [pkgs.gdb];
      };
    });
}
