#!/bin/sh -eu

# Create a new report file from the template

NEXT_REPORT_DATE=$(date -d "next tuesday" --rfc-3339=date)
export NEXT_REPORT_DATE

envsubst < template/report-template.md > "${NEXT_REPORT_DATE}-report.md"
