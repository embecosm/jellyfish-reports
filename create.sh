#!/bin/sh -eu

# Create a new report file from the template

NEXT_REPORT_DATE=$(date -d "next tuesday" --rfc-3339=date)

LAST_REPORT_DATE=$(date -d "last tuesday" --rfc-3339=date)
LAST_REPORT_FILENAME="${LAST_REPORT_DATE}-report.md"

BINUTILS_INSTRUCTION_COUNT="0"
BINUTILS_INSTRUCTION_TEST_COUNT="0"
BUILTINS_COMPLETED_COUNT="0"
BUILTINS_TESTED_COUNT="0"

WP1_COMPLETION=" "
WP2_COMPLETION=" "
WP3_COMPLETION=" "
WP4_COMPLETION=" "

if [ -f "$LAST_REPORT_FILENAME" ]; then
  echo "Using $LAST_REPORT_FILENAME values"
  BINUTILS_INSTRUCTION_COUNT=$(sed -n 's/^- Instructions added to binutils: \(.*\)\/.*/\1/p' "$LAST_REPORT_FILENAME")
  BINUTILS_INSTRUCTION_TEST_COUNT=$(sed -n 's/^- Binutils instructions tested: \(.*\)\/.*/\1/p' "$LAST_REPORT_FILENAME")
  BUILTINS_COMPLETED_COUNT=$(sed -n 's/^- Builtins completed: \(.*\)\/.*/\1/p' "$LAST_REPORT_FILENAME")
  BUILTINS_TESTED_COUNT=$(sed -n 's/^- Builtins tested: \(.*\)\/.*/\1/p' "$LAST_REPORT_FILENAME")  

  WP1_COMPLETION=$(sed -n 's/^- \[\(.*\)\] \*WP1\*.*/\1/p' "$LAST_REPORT_FILENAME")
  WP2_COMPLETION=$(sed -n 's/^- \[\(.*\)\] \*WP2\*.*/\1/p' "$LAST_REPORT_FILENAME")
  WP3_COMPLETION=$(sed -n 's/^- \[\(.*\)\] \*WP3\*.*/\1/p' "$LAST_REPORT_FILENAME")
  WP4_COMPLETION=$(sed -n 's/^- \[\(.*\)\] \*WP4\*.*/\1/p' "$LAST_REPORT_FILENAME")

fi


export NEXT_REPORT_DATE
export BINUTILS_INSTRUCTION_COUNT
export BINUTILS_INSTRUCTION_TEST_COUNT
export BUILTINS_COMPLETED_COUNT
export BUILTINS_TESTED_COUNT

export WP1_COMPLETION
export WP2_COMPLETION
export WP3_COMPLETION
export WP4_COMPLETION

envsubst < template/report-template.md > "${NEXT_REPORT_DATE}-report.md"
