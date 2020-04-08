# BabyC

Programming language based on C from college compilers class

## Installation

```bash
brew install flex 
brew install bison
git clone https://github.com/kistanod/BabyC
make
```

## Usage

```bash
./bcc filename.bc
```

## Run tests
```bash
chmod u+x tester.sh
sh tester.sh
```

## Implementation

Parser: [flex](https://en.wikipedia.org/wiki/Flex_(lexical_analyser_generator)).  
Scanner: [bison](https://en.wikipedia.org/wiki/GNU_Bison)