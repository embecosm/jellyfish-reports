{
  description = "Jellyfish project reports";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {

        packages.generator = pkgs.writeShellApplication {
          name = "jellyfish_report_generator";
          runtimeInputs = with pkgs; [
            coreutils # date(1) & basename(1)
            gettext # envsubst(1)
          ];
          text = builtins.readFile ./create.sh;
        };

        packages.reports = pkgs.stdenvNoCC.mkDerivation {
          pname = "reports";
          version = "0.1.0";

          buildInputs = builtins.attrValues {
            inherit (pkgs)
              gnumake
              pandoc
              texliveMedium
              ;
          };

          src = builtins.filterSource (
            path: type:
            let
              ignoreFiles = [
                "flake.nix"
                "flake.lock"
                ".gitignore"
                ".git"
              ];
            in
            if pkgs.lib.lists.any (p: p == (baseNameOf path)) ignoreFiles then false else true
          ) ./.;

          installPhase = ''
            mkdir -p $out/reports
            mv build/*.pdf $out/reports/
          '';

        };

        defaultPackage = self.packages.${system}.generator;

        devShells.default = pkgs.mkShellNoCC {
          inputsFrom = builtins.attrValues self.packages.${system};
          buildInputs = builtins.attrValues {
            inherit (pkgs)
              evince
              nixfmt
              ;
          };

        };
      }
    );

}
